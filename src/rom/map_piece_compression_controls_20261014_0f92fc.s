.setcpu "65816"
.segment "CODE"
.org $92FC
map_control_0f92fc:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
