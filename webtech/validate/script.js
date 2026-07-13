document.getElementById('registrationForm').addEventListener('submit', function(event) {
    // Prevent the form from refreshing the page on submit
    event.preventDefault();

    // Clear previous error messages
    const errorDivs = ['nameIrr', 'ageIrr', 'idIrr', 'emailIrr', 'phoneIrr', 'messageIrr'];
    errorDivs.forEach(id => document.getElementById(id).innerText = "");

    let isValid = true;

    // 1. Name Validation (Cannot be empty)
    const name = document.getElementById('name').value.trim();
    if (name === "") {
        document.getElementById('nameIrr').innerText = "Name is required.";
        isValid = false;
    }

    // 2. Age Validation (Must be a number and reasonable age)
    const age = document.getElementById('age').value.trim();
    if (age === "" || isNaN(age) || age <= 0) {
        document.getElementById('ageIrr').innerText = "Please enter a valid age.";
        isValid = false;
    }

    // 3. ID Validation (Cannot be empty)
    const id = document.getElementById('id').value.trim();
    if (id === "") {
        document.getElementById('idIrr').innerText = "ID is required.";
        isValid = false;
    }

    // 4. Email Validation (Basic regex check)
    const email = document.getElementById('email').value.trim();
    const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailPattern.test(email)) {
        document.getElementById('emailIrr').innerText = "Please enter a valid email address.";
        isValid = false;
    }

    // 5. Phone Validation (Basic digits check)
    const phone = document.getElementById('phone').value.trim();
    const phonePattern = /^[0-9]{7,15}$/; // Adjust length as needed
    if (!phonePattern.test(phone)) {
        document.getElementById('phoneIrr').innerText = "Please enter a valid phone number.";
        isValid = false;
    }

    // 6. Message Validation (Cannot be empty)
    const message = document.getElementById('message').value.trim();
    if (message === "") {
        document.getElementById('messageIrr').innerText = "Message cannot be empty.";
        isValid = false;
    }

    // If everything passes validation
    if (isValid) {
        alert("Form submitted successfully!");
        // You can now send data to a server using fetch() or form.submit()
    }
});