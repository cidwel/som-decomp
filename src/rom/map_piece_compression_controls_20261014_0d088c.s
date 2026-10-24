.setcpu "65816"
.segment "CODE"
.org $088C
map_control_0d088c:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $D9 ; row-distance/count
