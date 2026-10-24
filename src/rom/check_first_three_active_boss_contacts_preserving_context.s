; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-public-party-services.md.
.setcpu "65816"
.smart
.a8
.i16

test_boss_contact_with_three_party_actors = $125B

.segment "CODE"
.org $0363
check_first_three_active_boss_contacts_preserving_context:
    php
    phd
    phb
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .a16
    lda #$0200
    tcd
    .i16
    ldy #$0000
check_first_three_active_boss_contacts_preserving_context_c20375:
    tya
    xba
    asl
    clc
    .a16
    adc #$E600
    tax
    stx $87
    lda a:$0000,X
    .a16
    and #$00FF
    beq check_first_three_active_boss_contacts_preserving_context_c2038c
    phy
    jsr test_boss_contact_with_three_party_actors
    ply
check_first_three_active_boss_contacts_preserving_context_c2038c:
    iny
    .i16
    cpy #$0003
    bne check_first_three_active_boss_contacts_preserving_context_c20375
    plb
    pld
    plp
    rtl
