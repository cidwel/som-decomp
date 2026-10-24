.setcpu "65816"
.segment "CODE"
.org $7D9B
map_control_0c7d9b:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
