.setcpu "65816"
.segment "CODE"
.org $CF78
map_control_0fcf78:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
