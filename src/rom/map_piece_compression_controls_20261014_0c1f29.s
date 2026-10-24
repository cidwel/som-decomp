.setcpu "65816"
.segment "CODE"
.org $1F29
map_control_0c1f29:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
