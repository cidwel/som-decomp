; Initial equipment record pointers for the three heroes; docs/actor-hero-initialize.md.
.setcpu "65816"
.segment "CODE"
.org $4E2B
initial_hero_equipment_record_pointers:
    .word $57BD, $57C1, $57C5
