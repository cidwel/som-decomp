.setcpu "65816"
.segment "CODE"
.org $7806
map_control_0d7806:
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
