.setcpu "65816"
.segment "CODE"
.org $2DBD
map_control_0f2dbd:
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E5 ; previous-row copy count
