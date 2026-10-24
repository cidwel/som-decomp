.setcpu "65816"
.segment "CODE"
.org $9EAE
map_control_0d9eae:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
