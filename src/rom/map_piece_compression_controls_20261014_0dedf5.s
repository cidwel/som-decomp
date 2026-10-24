.setcpu "65816"
.segment "CODE"
.org $EDF5
map_control_0dedf5:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
