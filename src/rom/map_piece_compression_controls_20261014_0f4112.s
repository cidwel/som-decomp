.setcpu "65816"
.segment "CODE"
.org $4112
map_control_0f4112:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $F2 ; progressive-copy count
    .byte $E4 ; previous-row copy count
