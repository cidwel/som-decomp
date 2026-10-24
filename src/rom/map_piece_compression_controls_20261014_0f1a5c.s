.setcpu "65816"
.segment "CODE"
.org $1A5C
map_control_0f1a5c:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
