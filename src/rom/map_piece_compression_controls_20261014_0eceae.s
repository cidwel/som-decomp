.setcpu "65816"
.segment "CODE"
.org $CEAE
map_control_0eceae:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
