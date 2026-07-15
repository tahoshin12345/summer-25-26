 document.getElementById('registrationForm').addEventListener('submit', function(event) {
            event.preventDefault();

            const errorDivs = ['nameErr', 'ageErr', 'idErr', 'emailErr', 'phoneErr', 'messageErr'];
            errorDivs.forEach(id => document.getElementById(id).innerText = "");

            let isValid = true;

            const name = document.getElementById('name').value.trim();
            if (name === "") {
                document.getElementById('nameErr').innerText = "Name is required.";
                isValid = false;
            }

            const age = document.getElementById('age').value.trim();
            if (age === "" || isNaN(age) || age <= 18) {
                document.getElementById('ageErr').innerText = "Please enter a valid age.";
                isValid = false;
            }

            const id = document.getElementById('id').value.trim();
            if (id === "") {
                document.getElementById('idErr').innerText = "ID is required.";
                isValid = false;
            }

            const email = document.getElementById('email').value.trim();
            const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
            if (!emailPattern.test(email)) {
                document.getElementById('emailErr').innerText = "Please enter a valid email address.";
                isValid = false;
            }

            const phone = document.getElementById('phone').value.trim();
            const phonePattern = /^[0-9]{11}$/;
            if (!phonePattern.test(phone)) {
                document.getElementById('phoneErr').innerText = "Please enter a valid phone number.";
                isValid = false;
            }

            const message = document.getElementById('message').value.trim();
            if (message <=10) {
                document.getElementById('messageErr').innerText = "Message must be 10 charecter";
                isValid = false;
            }

            if (isValid) {
                alert("Form submitted successfully!");
            }
        });