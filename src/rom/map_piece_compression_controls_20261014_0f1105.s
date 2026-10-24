.setcpu "65816"
.segment "CODE"
.org $1105
map_control_0f1105:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
