.setcpu "65816"
.segment "CODE"
.org $3943
map_control_0f3943:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
