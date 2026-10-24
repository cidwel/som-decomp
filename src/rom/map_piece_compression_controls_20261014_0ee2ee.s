.setcpu "65816"
.segment "CODE"
.org $E2EE
map_control_0ee2ee:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E1 ; previous-row copy count
