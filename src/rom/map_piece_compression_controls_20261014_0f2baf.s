.setcpu "65816"
.segment "CODE"
.org $2BAF
map_control_0f2baf:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
