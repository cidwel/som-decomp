.setcpu "65816"
.segment "CODE"
.org $41DB
map_control_0f41db:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
