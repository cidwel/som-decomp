.setcpu "65816"
.segment "CODE"
.org $54B1
map_control_0c54b1:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
