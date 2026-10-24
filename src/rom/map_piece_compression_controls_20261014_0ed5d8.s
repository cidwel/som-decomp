.setcpu "65816"
.segment "CODE"
.org $D5D8
map_control_0ed5d8:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
