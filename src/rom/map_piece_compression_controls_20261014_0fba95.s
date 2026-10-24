.setcpu "65816"
.segment "CODE"
.org $BA95
map_control_0fba95:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
