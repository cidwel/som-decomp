.setcpu "65816"
.segment "CODE"
.org $BDF8
map_control_0dbdf8:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
