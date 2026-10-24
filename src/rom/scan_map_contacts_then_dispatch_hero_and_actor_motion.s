; Recovered Secret of Mana USA routine; behaviour documented in docs/map-contact-motion-caller.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01cd4e = $1CD4E
routine_c0d1fe = $D1FE
routine_c0d5ed = $D5ED

.segment "CODE"
.org $D5C0
scan_map_contacts_then_dispatch_hero_and_actor_motion:
    sep #$20
    bit $F1
    bvc scan_map_contacts_then_dispatch_hero_and_actor_motion_c0d5c7
    rts
scan_map_contacts_then_dispatch_hero_and_actor_motion_c0d5c7:
    phb
    .a8
    lda #$7E
    pha
    plb
    jsl f:routine_01cd4e
    rep #$10
    .i16
    ldx #$0000
    jsr routine_c0d5ed
    rep #$10
    .i16
    ldx #$0200
    jsr routine_c0d5ed
    rep #$10
    .i16
    ldx #$0400
    jsr routine_c0d5ed
    jsr routine_c0d1fe
    plb
    rts
