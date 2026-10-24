.setcpu "65816"
.segment "CODE"
.org $DF5A
map_control_0edf5a:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6C ; row-distance/count
