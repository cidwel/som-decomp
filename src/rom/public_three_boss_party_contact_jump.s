; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-public-party-services.md.
.setcpu "65816"
.smart
.a8
.i16

check_first_three_active_boss_contacts_preserving_context = $0363

.segment "CODE"
.org $0015
public_three_boss_party_contact_jump:
    jmp check_first_three_active_boss_contacts_preserving_context
