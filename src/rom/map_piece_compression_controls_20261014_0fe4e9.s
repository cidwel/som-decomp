.setcpu "65816"
.segment "CODE"
.org $E4E9
map_control_0fe4e9:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
