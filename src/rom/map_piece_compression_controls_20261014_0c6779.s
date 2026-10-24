.setcpu "65816"
.segment "CODE"
.org $6779
map_control_0c6779:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
