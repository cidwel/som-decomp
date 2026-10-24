.setcpu "65816"
.segment "CODE"
.org $85FC
map_control_0e85fc:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
