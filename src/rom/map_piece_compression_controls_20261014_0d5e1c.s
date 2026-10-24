.setcpu "65816"
.segment "CODE"
.org $5E1C
map_control_0d5e1c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E4 ; previous-row copy count
