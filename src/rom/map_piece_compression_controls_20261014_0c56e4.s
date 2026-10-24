.setcpu "65816"
.segment "CODE"
.org $56E4
map_control_0c56e4:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
