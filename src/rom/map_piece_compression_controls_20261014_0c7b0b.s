.setcpu "65816"
.segment "CODE"
.org $7B0B
map_control_0c7b0b:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
