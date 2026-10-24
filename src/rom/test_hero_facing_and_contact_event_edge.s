; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D107
test_hero_facing_and_contact_event_edge:
    lda a:$E010,X
    bne test_hero_facing_and_contact_event_edge_c1d112
    bit $07
    bmi test_hero_facing_and_contact_event_edge_c1d128
    bpl test_hero_facing_and_contact_event_edge_c1d12b
test_hero_facing_and_contact_event_edge_c1d112:
    .a8
    cmp #$02
    bcs test_hero_facing_and_contact_event_edge_c1d11c
    bit $07
    bpl test_hero_facing_and_contact_event_edge_c1d128
    bmi test_hero_facing_and_contact_event_edge_c1d12b
test_hero_facing_and_contact_event_edge_c1d11c:
    bne test_hero_facing_and_contact_event_edge_c1d124
    bit $06
    bpl test_hero_facing_and_contact_event_edge_c1d128
    bmi test_hero_facing_and_contact_event_edge_c1d12b
test_hero_facing_and_contact_event_edge_c1d124:
    bit $06
    bpl test_hero_facing_and_contact_event_edge_c1d12b
test_hero_facing_and_contact_event_edge_c1d128:
    .a8
    lda #$01
    rts
test_hero_facing_and_contact_event_edge_c1d12b:
    sec
