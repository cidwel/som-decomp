.setcpu "65816"
.segment "CODE"
.org $1AB6
map_control_0d1ab6:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
