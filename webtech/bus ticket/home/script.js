document.getElementById('contactForm').addEventListener('submit', function(event) {
    // Prevent the default form submission page reload
    event.preventDefault();

    // 1. Fetch DOM Inputs
    const nameInput = document.getElementById('name').value.trim();
    const emailInput = document.getElementById('email').value.trim();
    const phoneInput = document.getElementById('phone').value.trim();
    const ageInput = document.getElementById('age').value.trim();
    const subjectInput = document.getElementById('subject').value.trim();
    const messageInput = document.getElementById('message').value.trim();

    // 2. Clear previous errors and success state
    const errorElements = document.querySelectorAll('.error-msg');
    errorElements.forEach(el => el.innerText = '');
    
    const successSummary = document.getElementById('success-summary');
    successSummary.style.display = 'none';
    successSummary.innerHTML = '';

    let isValid = true;

    // --- VALIDATION CORE LOOP ---

    // Rule 1: Name (Cannot be empty)
    if (nameInput === '') {
        document.getElementById('nameError').innerText = 'Name field is required.';
        isValid = false;
    }

    // Rule 2: Email (Proper format check via Regex)
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (emailInput !== '' && !emailRegex.test(emailInput)) {
        document.getElementById('emailError').innerText = 'Please enter a valid email format (e.g., user@example.com).';
        isValid = false;
    } else if (emailInput === '') {
        document.getElementById('emailError').innerText = 'Email field is required.';
        isValid = false;
    }

    // Rule 3: Phone (Custom Check 1: Valid 11-digit mobile string patterns)
    const phoneRegex = /^01[3-9]\d{8}$/;
    if (phoneInput !== '' && !phoneRegex.test(phoneInput)) {
        document.getElementById('phoneError').innerText = 'Enter a valid 11-digit number starting with 01.';
        isValid = false;
    } else if (phoneInput === '') {
        document.getElementById('phoneError').innerText = 'Phone number is required.';
        isValid = false;
    }

    // Rule 4: Age (Custom Check 2: Minimum value bounds evaluation)
    const ageNum = parseInt(ageInput, 10);
    if (ageInput !== '' && (isNaN(ageNum) || ageNum < 18)) {
        document.getElementById('ageError').innerText = 'You must be at least 18 years old to register.';
        isValid = false;
    } else if (ageInput === '') {
        document.getElementById('ageError').innerText = 'Age field is required.';
        isValid = false;
    }

    // Rule 5: Subject (Custom Check 3: Reject absolute digit presence)
    const digitRegex = /\d/;
    if (subjectInput !== '' && digitRegex.test(subjectInput)) {
        document.getElementById('subjectError').innerText = 'Subject cannot contain numbers.';
        isValid = false;
    } else if (subjectInput === '') {
        document.getElementById('subjectError').innerText = 'Subject field is required.';
        isValid = false;
    }

    // Rule 6: Message (Minimum 10 characters string length check)
    if (messageInput !== '' && messageInput.length < 10) {
        document.getElementById('messageError').innerText = 'Message must be at least 10 characters long.';
        isValid = false;
    } else if (messageInput === '') {
        document.getElementById('messageError').innerText = 'Message field is required.';
        isValid = false;
    }

    // --- REGISTRATION SUCCESS PROCESSING ---
    if (isValid) {
        successSummary.style.display = 'block';
        successSummary.innerHTML = `
            <strong>Registration Completed Successfully!</strong><br><br>
            <strong>Summary Records Saved:</strong><br>
            • Name: ${nameInput}<br>
            • Email: ${emailInput}<br>
            • Phone: ${phoneInput}<br>
            • Age: ${ageNum}<br>
            • Subject: ${subjectInput}<br>
            • Message: ${messageInput}
        `;
        // Clear out the text form fields cleanly after processing data
        document.getElementById('contactForm').reset();
    }
});