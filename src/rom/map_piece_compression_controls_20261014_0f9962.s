.setcpu "65816"
.segment "CODE"
.org $9962
map_control_0f9962:
    .byte $E8 ; backreference distance high bits
    .byte $5E ; distance low bit/count
