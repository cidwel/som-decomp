.setcpu "65816"
.segment "CODE"
.org $0DBC
map_control_0e0dbc:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
