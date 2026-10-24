.setcpu "65816"
.segment "CODE"
.org $4B54
map_control_0d4b54:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
