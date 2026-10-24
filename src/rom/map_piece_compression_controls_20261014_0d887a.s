.setcpu "65816"
.segment "CODE"
.org $887A
map_control_0d887a:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
