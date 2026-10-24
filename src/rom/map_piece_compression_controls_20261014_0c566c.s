.setcpu "65816"
.segment "CODE"
.org $566C
map_control_0c566c:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
