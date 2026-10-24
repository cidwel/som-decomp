.setcpu "65816"
.segment "CODE"
.org $9B7C
map_control_0e9b7c:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
