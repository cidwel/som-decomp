; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c1d517 = $D517

.segment "CODE"
.org $D285
record_contact_presentation_byte_and_volume:
    bit $95
    bmi record_contact_presentation_byte_and_volume_c1d28e
    sta $95
    brl routine_c1d517
record_contact_presentation_byte_and_volume_c1d28e:
    rts
