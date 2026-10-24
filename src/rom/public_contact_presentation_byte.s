; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16

record_contact_presentation_byte_and_volume = $D285

.segment "CODE"
.org $D28F
public_contact_presentation_byte:
    jsr record_contact_presentation_byte_and_volume
    rtl
