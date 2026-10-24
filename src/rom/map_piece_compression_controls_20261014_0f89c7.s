.setcpu "65816"
.segment "CODE"
.org $89C7
map_control_0f89c7:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
