.setcpu "65816"
.segment "CODE"
.org $783F
map_control_0c783f:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
