.setcpu "65816"
.segment "CODE"
.org $BC6C
map_control_0fbc6c:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
