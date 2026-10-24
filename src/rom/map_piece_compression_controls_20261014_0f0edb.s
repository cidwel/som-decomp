.setcpu "65816"
.segment "CODE"
.org $0EDB
map_control_0f0edb:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
