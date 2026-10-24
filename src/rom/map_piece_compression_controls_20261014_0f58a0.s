.setcpu "65816"
.segment "CODE"
.org $58A0
map_control_0f58a0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
