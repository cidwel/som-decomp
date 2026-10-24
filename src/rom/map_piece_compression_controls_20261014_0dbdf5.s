.setcpu "65816"
.segment "CODE"
.org $BDF5
map_control_0dbdf5:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
