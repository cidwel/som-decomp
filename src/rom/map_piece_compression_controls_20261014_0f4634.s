.setcpu "65816"
.segment "CODE"
.org $4634
map_control_0f4634:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
