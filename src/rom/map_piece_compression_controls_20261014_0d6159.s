.setcpu "65816"
.segment "CODE"
.org $6159
map_control_0d6159:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
