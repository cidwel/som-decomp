.setcpu "65816"
.segment "CODE"
.org $47BE
map_control_0c47be:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
