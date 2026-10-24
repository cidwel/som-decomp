.setcpu "65816"
.segment "CODE"
.org $2105
map_control_0f2105:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
