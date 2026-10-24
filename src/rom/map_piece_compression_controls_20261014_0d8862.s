.setcpu "65816"
.segment "CODE"
.org $8862
map_control_0d8862:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
