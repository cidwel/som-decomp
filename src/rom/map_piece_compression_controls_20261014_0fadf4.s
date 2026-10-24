.setcpu "65816"
.segment "CODE"
.org $ADF4
map_control_0fadf4:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
