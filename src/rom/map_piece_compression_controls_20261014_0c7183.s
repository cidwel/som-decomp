.setcpu "65816"
.segment "CODE"
.org $7183
map_control_0c7183:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
