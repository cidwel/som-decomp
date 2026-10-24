.setcpu "65816"
.segment "CODE"
.org $613A
map_control_0d613a:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
