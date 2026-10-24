.setcpu "65816"
.segment "CODE"
.org $DF5E
map_control_0ddf5e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
